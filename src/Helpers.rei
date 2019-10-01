[@bs.deriving abstract]
type transaction = {
	amount : string,
	date : Js.Date.t,
	business : string,
	name : string,
	[@bs.as "type"] type_ : string
};

[@bs.deriving abstract]
type card_address_geo = {
	lat : string,
	lng : string
};

[@bs.deriving abstract]
type card_company = {
	name : string,
	catchPhrase : string,
	bs : string
};

[@bs.deriving abstract]
type card_post = {
	words : string,
	sentence : string,
	sentences : string,
	paragraph : string
};

[@bs.deriving abstract]
type card_address = {
	[@bs.optional] street : string,
	[@bs.optional] streetA : string,
	[@bs.optional] streetB : string,
	[@bs.optional] streetC : string,
	[@bs.optional] streetD : string,
	city : string,
	state : string,
	country : string,
	zipcode : string,
	geo : card_address_geo
};

[@bs.deriving abstract]
type card = {
	name : string,
	username : string,
	email : string,
	address : card_address,
	phone : string,
	website : string,
	company : card_company,
	posts : Js.Array.t(card_post),
	accountHistory : Js.Array.t(transaction)
};

[@bs.deriving abstract]
type contextual_card = {
	name : string,
	username : string,
	avatar : string,
	email : string,
	dob : Js.Date.t,
	phone : string,
	address : card_address,
	website : string,
	company : card_company
};

let randomize : (~arr: Js.Array.t('a)=?, unit) => 'a;
let slugify : (~str: string=?, unit) => string;
let replaceSymbolWithNumber : (~str: string=?, ~symbol: string=?, unit) => string;
let replaceSymbols : (~str: string=?, unit) => string;
let shuffle : (~o: Js.Array.t('a)=?, unit) => Js.Array.t('a);
let mustache : (~str: string=?, ~data: Js.Dict.t('a)=?, unit) => string;
let createCard : unit => card;
let contextualCard : unit => contextual_card;
