import React, { useContext, useEffect } from 'react'
import { useHistory } from 'react-router';
import { AutoPilot } from '../components/AutoPilot';
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext'
import { slime } from '../dialogues/slime'
import { dialogue } from '../util/randGen';

export const CombatScreen = (props) => {
	const {
		characterHP,
		defeat,
		encounterAction,
		encounterLocation,
		enemyHP,
		victory,
		setCharacterHP,
		setDefeat,
		setEncounterAction,
		setEncounterLocation,
		setEnemyHP,
		setEnemyName,
		setVictory,
	} = useContext(SiteContext);
	const history = useHistory();

	useEffect(() => {
		setEnemyName('Slime');
		setEncounterLocation(`
The Fluffy fields?!?! 
How dangerous could that possibly be? 
But wait.`
		);
		setEncounterAction(slime.appears);
	}, [])

	// Victory effects
	useEffect(() => {
		if (enemyHP <= 0) {
			setVictory(true);
			setEncounterAction(dialogue(slime.victory))
		}
	}, [enemyHP])

	// Defeat effects
	useEffect(() => {
		if (characterHP <= 0) {
			setDefeat(true)
			setEncounterAction(dialogue(slime.defeated))
		}
	})

	return (
		<div className='travel-screen-wrapper rpgui-container framed-golden'>
			<div className='controls'>
				<Button disabled={enemyHP <= 0} onClick={(e) => {
					e.preventDefault();
					setEnemyHP(enemyHP - 50)
					{ (enemyHP > 0) && setEncounterAction(dialogue(slime.attacked)) }
					setTimeout(() => {
						if (enemyHP > 0) {
							setCharacterHP(characterHP - 10);
							setEncounterAction(dialogue(slime.attacking))
						}
					}, 3000);
				}}><p>Attack</p></Button>
				<Button disabled><p>Spell</p></Button>
				<Button disabled><p>Ability</p></Button>
				<Button disabled><p>Item</p></Button>
				<Button onClick={(e) => {
					e.preventDefault();
					setEncounterAction(dialogue(slime.evaded));
					setTimeout(() => {
						history.push('/Travel');
					}, 2000);
				}} ><p>Flee</p></Button>
				<Button color='golden' to='/'><p>Menu</p></Button>

			</div>
			<div className='description rpgui-container framed-golden-2'>
				<AutoPilot />
				<p>{encounterLocation}</p>
				<p>{encounterAction}</p>


			</div>

		</div>
	)
}