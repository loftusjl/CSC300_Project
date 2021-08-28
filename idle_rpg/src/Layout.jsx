import React, { useState } from 'react';
import { SiteContext } from './context/SiteContext';
import { CharacterStats } from './components/characterStats'
import { EnemyStats } from './components/enemyStats';

const Layout = (props) => {
	const [characterAttackBonus, setCharacterAttackBonus] = useState(0);
	const [characterDefenseBonus, setCharacterDefenseBonus] = useState(0);
	const [characterEvasionBonus, setCharacterEvasionBonus] = useState(0);
	const [characterHP, setCharacterHP] = useState(0);
	const [characterMaxHP, setCharacterMaxHP] = useState(0);
	const [characterName, setCharacterName] = useState('');
	const [encounterAction, setEncounterAction] = useState('');
	const [encounterLocation, setEncounterLocation] = useState('');
	const [enemyAttackBonus, setEnemyAttackBonus] = useState(0);
	const [enemyDefenseBonus, setEnemyDefenseBonus] = useState(0);
	const [enemyEvasionBonus, setEnemyEvasionBonus] = useState(0);
	const [enemyHP, setEnemyHP] = useState(0);
	const [enemyMaxHP, setEnemyMaxHP] = useState(0);
	const [enemyName, setEnemyName] = useState('');
	const [toggleAutopilot, setToggleAutopilot] = useState(false);

	return (
		<SiteContext.Provider value={{
			characterAttackBonus,
			characterDefenseBonus,
			characterEvasionBonus,
			characterHP,
			characterMaxHP,
			characterName,
			encounterAction,
			encounterLocation,
			enemyAttackBonus,
			enemyDefenseBonus,
			enemyEvasionBonus,
			enemyHP,
			enemyMaxHP,
			enemyName,
			setCharacterAttackBonus,
			setCharacterDefenseBonus,
			setCharacterEvasionBonus,
			setCharacterHP,
			setCharacterMaxHP,
			setCharacterName,
			setEncounterAction,
			setEncounterLocation,
			setEnemyAttackBonus,
			setEnemyDefenseBonus,
			setEnemyEvasionBonus,
			setEnemyHP,
			setEnemyMaxHP,
			setEnemyName,
			setToggleAutopilot,
			toggleAutopilot,
		}}>
			<div className="rpgui-content">
				<div className='inner rpgui-container framed'>
					<div>
						<h1 className='title'>Idle RPG!</h1>
						<h3>The text-based RPG of the future is now!</h3>
					</div>
					<div className='wrapper'>
						{props.children}</div>
					<div className='status-block'>
						{characterName && <CharacterStats />}
						{enemyName && <EnemyStats />}
					</div>
				</div>
			</div>
		</SiteContext.Provider>
	)
}

export default Layout;