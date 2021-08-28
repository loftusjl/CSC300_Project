import React, { useState, useContext, useEffect } from 'react'
import { AutoPilot } from '../components/AutoPilot';
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext'
import { slime } from '../dialogues/slime'

export const CombatScreen = (props) => {
	const { setEnemyName, encounterAction, encounterLocation, setEncounterLocation, setEncounterAction } = useContext(SiteContext);

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
				<Button onClick={() => {
					setEncounterAction('Swing and a miss!')
				}}><p>Attack</p></Button>
				<Button disabled><p>Spell</p></Button>
				<Button disabled><p>Ability</p></Button>
				<Button disabled><p>Item</p></Button>
				<Button ><p>Flee</p></Button>
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