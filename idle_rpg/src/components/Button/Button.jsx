import React from 'react'
import { Link } from 'react-router-dom'

export const Button = ({ to, color, ...props }) => {
	return (
		<Link
			to={to || ''}
		>
			<button {...props} className={`rpgui-button ${color}`}>
				{props.children}
			</button>
		</Link>
	)
}

export default Button;