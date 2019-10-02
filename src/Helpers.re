let nullable = Faker.nullable;

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

[@bs.deriving abstract]
type t = {
	slugify : Js.Nullable.t(string) => string,
	replaceSymbolWithNumber : (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
	replaceSymbols : Js.Nullable.t(string) => string,
	createCard : unit => card,
	contextualCard : unit => contextual_card,
	userCard : unit => contextual_card,
	createTransaction : unit => transaction
};

[@bs.module "faker"] external fakers : t = "helpers";

let slugify = (~str=?, ()) => slugify(fakers, nullable(str));
let replaceSymbolWithNumber = (~str=?, ~symbol=?, ()) => replaceSymbolWithNumber(fakers, nullable(str), nullable(symbol));
let replaceSymbols = (~str=?, ()) => replaceSymbols(fakers, nullable(str));
let createCard = () => createCard(fakers, ());
let contextualCard = () => contextualCard(fakers, ());

[@bs.module "faker"] [@bs.scope "helpers"]
external randomize : Js.Nullable.t(Js.Array.t('a)) => 'a = "";
let randomize = (~arr=?, ()) => randomize(nullable(arr));

[@bs.module "faker"] [@bs.scope "helpers"]
external shuffle : Js.Nullable.t(Js.Array.t('a)) => Js.Array.t('a) = "";
let shuffle = (~o=?, ()) => shuffle(nullable(o));

[@bs.module "faker"] [@bs.scope "helpers"]
external mustache : (Js.Nullable.t(string), Js.Nullable.t(Js.Dict.t('a))) => string = "";
let mustache = (~str=?, ~data=?, ()) => mustache(nullable(str), nullable(data));
