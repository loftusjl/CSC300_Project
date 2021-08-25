import React from 'react'
import { NavLink } from 'react-router-dom';
import { Button } from '../components/Button/Button'

export function SelectMenu(props) {
	return (
		<div className='select-menu-wrapper'>
			<div className='select-menu'>
				<Button><p>Continue Game</p></Button>
				<Button><p>Create New Character</p></Button>
				<Button disabled><p>Item Shop</p></Button>
				<Button disabled><p>Settings</p></Button>
				<Button><p>Exit Game</p></Button>

			</div>
			<div className='select-menu motd'><h3>Message of the Day:</h3> <p>Fate is what you make.</p></div>
		</div>
	)
}

export default SelectMenu;