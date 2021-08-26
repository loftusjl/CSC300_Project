import { createContext } from "react";

export const SiteContext = createContext({
	characterName: '',
	setCharacterName: () => { },
});