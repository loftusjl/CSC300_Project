import React, { useState, useContext, useEffect } from 'react'
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext'

export const CombatScreen = (props) => {
	const { setEnemyName, encounterAction, encounterLocation, setEncounterLocation, setEncounterAction } = useContext(SiteContext);
	const [desc, setDesc] = useState(`
The Fluffy fields?!?! 
How dangerous could that possibly be? 
But wait. 
A wild slime pulsates from a 
nearby bush and blocks your path!`);

	useEffect(() => {
		setEnemyName('Slime');
		// set
	}, [])
	return (
		<div className='travel-screen-wrapper rpgui-container framed-golden'>
			<div className='controls'>
				<Button><p>Attack</p></Button>
				<Button disabled><p>Spell</p></Button>
				<Button disabled><p>Ability</p></Button>
				<Button disabled><p>Item</p></Button>
				<Button ><p>Flee</p></Button>
				<Button to='/'><p>Menu</p></Button>

			</div>
			<div className='description rpgui-container framed-golden-2'>
				<p>{desc}</p>
				<p>{ }</p>


			</div>

		</div>
	)
}