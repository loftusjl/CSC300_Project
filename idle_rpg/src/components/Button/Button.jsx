import React from 'react'
import { Link } from 'react-router-dom'

export const Button = ({ to, ...props }) => {
	return (
		<Link
			to={to}
		>
			<button {...props} className="rpgui-button golden">
				{props.children}
			</button>
		</Link>
	)
}

export default Button;