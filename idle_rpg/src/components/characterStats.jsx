import React, { useContext } from 'react'
import { StatBlock } from './statBlock'
import { SiteContext } from '../context/SiteContext'

export const CharacterStats = (props) => {
	const { characterName, characterHP, characterMaxHP } = useContext(SiteContext)
	return (
		<div className='stats rpgui-container framed-golden-2'>
			<h3>{characterName}</h3>
			<StatBlock
				label='Hit Points'
				decimalValue={characterMaxHP / characterHP}
				percentValue={`${(characterMaxHP / characterHP) * 100}%`}
				color='red'
			/>
			<StatBlock
				label='Experience'
				decimalValue='0.2'
				percentValue='20%'
				color=''
			/>
		</div>

	)
}