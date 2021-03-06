import React, { useContext, useState, useEffect } from 'react'
import { Button } from '../components/Button/Button'
import { SiteContext } from '../context/SiteContext';

export function SelectMenu(props) {
	const { characterName, setCharacterName, setEnemyName } = useContext(SiteContext);
	const [createCharacter, setCreateCharacter] = useState(false);

	useEffect(() => {
		setEnemyName('');
	}, [])

	const handleChange = (e) => {
		setCharacterName(e.target.value)
	}
	return (
		<div className='select-menu-wrapper'>
			<div className='select-menu'>
				<Button color='golden' disabled={!characterName.length > 0} to='/Travel'><p>Continue Game</p></Button>
				<Button color='golden'
					onClick={() => setCreateCharacter(!createCharacter)}
				><p>Create New Character</p></Button>
				<Button color='golden' disabled><p>Item Shop</p></Button>
				<Button color='golden' disabled><p>Settings</p></Button>
				<Button
					onClick={(e) => {
						e.preventDefault();
						window.alert(`Exit game is not a feature that works unless we scripted you opening the tab. Just close your browser.`);
					}}
				><p>Exit Game</p></Button>
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
							><p>Start</p></Button>

						</div>
					</div>
				)}
			</div>

		</div>
	)
}

export default SelectMenu;