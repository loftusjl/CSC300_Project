import React, { useContext, useState } from 'react'
import { NavLink } from 'react-router-dom';
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext';

export function SelectMenu(props) {
	const { characterName, setCharacterName } = useContext(SiteContext);
	const [createCharacter, setCreateCharacter] = useState(false);

	const handleChange = (e) => {
		setCharacterName(e.target.value)
	}
	return (
		<div className='select-menu-wrapper'>
			<div className='select-menu'>
				<Button disabled={!characterName.length > 0} to='/Travel'><p>Continue Game</p></Button>
				<Button
					onClick={() => setCreateCharacter(!createCharacter)}
				><p>Create New Character</p></Button>
				<Button disabled><p>Item Shop</p></Button>
				<Button disabled><p>Settings</p></Button>
				<Button><p>Exit Game</p></Button>
			</div>
			<div className='select-menu'>
				{!createCharacter && (
					<div className='motd'>
						<h3>Message of the Day:</h3>
						<p>There's no fate but what we make for ourselves.</p>
						<em>-Gandalf probably. I dunno, I never watched Star Trek.</em>
					</div>
				)}
				{createCharacter && (
					<div className='rpgui-container framed-golden'>
						<h3>What shalth thou be called'th?</h3>
						<input placeholder='Enter character name' name='characterName' value={characterName}
							onChange={handleChange} />
						<div className='control-row'>
							<button className='rpgui-button' onClick={() => setCharacterName('')}><p>Reset</p></button>
							<Button className='rpgui-button' to='/Travel'
							><p>Adventure!</p></Button>

						</div>
					</div>
				)}
			</div>

		</div>
	)
}

export default SelectMenu;