export const range = (low, high) =>{
	low = Math.ceil(low);
	high = Math.floor(high);
	return Math.round(Math.random() * (high - low) + low %1);
}

export const dialogue = (array) =>{
	return array[range(0, array.length - 1)];
}

export default range;