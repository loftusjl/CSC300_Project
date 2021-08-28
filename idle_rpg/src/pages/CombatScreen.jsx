import React, { useContext, useEffect } from 'react'
import { useHistory } from 'react-router';
import { AutoPilot } from '../components/AutoPilot';
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext'
import { slime } from '../dialogues/slime'
import { dialogue } from '../util/randGen';

export const CombatScreen = (props) => {
	const {
		encounterAction,
		encounterLocation,
		setEncounterAction,
		setEncounterLocation,
		setEnemyName,
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
	return (
		<div className='travel-screen-wrapper rpgui-container framed-golden'>
			<div className='controls'>
				<Button onClick={(e) => {
					e.preventDefault();
					setEncounterAction(dialogue(slime.attacked))
					setTimeout(() => {
						setEncounterAction(dialogue(slime.attacking))
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