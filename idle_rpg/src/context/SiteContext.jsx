import { createContext } from "react";

export const SiteContext = createContext({
	characterName: '',
	characterHP: 0,
	characterAttackBonus: 0,
	characterEvasionBonus: 0,
	characterDefenseBonus: 0,
	enemyName: '',
	enemyHP: 0,
	enemyAttackBonus: 0,
	enemyEvasionBonus: 0,
	enemyDefenseBonus: 0,
	setCharacterName: () => { },
	setCharacterHP: () => { },
	setCharacterAttackBonus: () => { },
	setCharacterEvasionBonus: () => { },
	setCharacterDefenseBonus: () => { },
	setEnemyName: () => { },
	setEnemyHP: () => { },
	setEnemyAttackBonus: () => { },
	setEnemyEvasionBonus: () => { },
	setEnemyDefenseBonus: () => { },
});