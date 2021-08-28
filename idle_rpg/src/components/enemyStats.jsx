import React, { useContext } from 'react'
import { StatBlock } from './statBlock'
import { SiteContext } from '../context/SiteContext'

export const EnemyStats = (props) => {
	const { enemyName } = useContext(SiteContext)
	return (
		<div className='stats rpgui-container framed-golden-2'>
			<h3>{enemyName}</h3>
			<StatBlock
				label='Hit Points'
				decimalValue='0.4'
				percentValue='40%'
				color='red'
			/>
			<StatBlock
				label='Mana'
				decimalValue='0.2'
				percentValue='20%'
				color='blue'
			/>
		</div>

	)
}