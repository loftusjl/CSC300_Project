import React from 'react'
import { StatBlock } from '../components/statBlock'

export const TravelScreen = (props) => {
	return (
		<StatBlock
			label='Hit Points'
			decimalValue='0.4'
			percentValue='40%'
			color='red'
		/>
	)
}