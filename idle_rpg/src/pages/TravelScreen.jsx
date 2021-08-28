import React, { useState, useContext, useEffect } from 'react'
import { AutoPilot } from '../components/AutoPilot';
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext';

export const TravelScreen = (props) => {
	const { setEnemyName } = useContext(SiteContext)
	const [desc, setDesc] = useState('You are at a crossroads. Where do you choose to venture?');

	useEffect(() => {
		setEnemyName('');
	}, [])

	return (
		<div className='travel-screen-wrapper rpgui-container framed-golden'>
			<div className='controls'>
				<Button color='golden' to='/Combat'><p>Fluffy Fields</p></Button>
				<Button color='golden' disabled><p>Dim Forest</p></Button>
				<Button color='golden' disabled><p>Gore Cave</p></Button>
				<Button color='golden' disabled><p>Evil Tower</p></Button>
				<Button color='golden' to='/'><p>Menu</p></Button>

			</div>
			<div className='description rpgui-container framed-golden-2'>
				<AutoPilot />
				<p>{desc}</p>


			</div>

		</div>
	)
}