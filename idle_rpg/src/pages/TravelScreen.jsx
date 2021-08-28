import React, { useState } from 'react'
import { Button } from '../components/Button/Button'

export const TravelScreen = (props) => {
	const [desc, setDesc] = useState('You are at a crossroads. Where do you choose to venture?');
	return (
		<div className='travel-screen-wrapper rpgui-container framed-golden'>
			<div className='controls'>
				<Button to='/Combat'><p>Fluffy Fields</p></Button>
				<Button disabled><p>Dim Forest</p></Button>
				<Button disabled><p>Gore Cave</p></Button>
				<Button disabled><p>Evil Tower</p></Button>
				<Button to='/'><p>Menu</p></Button>

			</div>
			<div className='description rpgui-container framed-golden-2'>
				<p>{desc}</p>


			</div>

		</div>
	)
}