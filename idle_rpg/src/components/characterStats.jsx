import React from 'react'
import { StatBlock } from './statBlock'

export const CharacterStats = (props) => {
	return (
		<div className='character-stats'>
			<StatBlock
				label='Hit Points'
				decimalValue='0.4'
				percentValue='40%'
				color='red'
			/>
		</div>

	)
}