let nullable = Faker.nullable;

type transaction = {
  amount: string,
  date: Js.Date.t,
  business: string,
  name: string,
  [@bs.as "type"]
  type_: string,
};

type card_address_geo = {
  lat: string,
  lng: string,
};

type card_company = {
  name: string,
  catchPhrase: string,
  bs: string,
};

type card_post = {
  words: string,
  sentence: string,
  sentences: string,
  paragraph: string,
};

type card_address = {
  street: option(string),
  streetA: option(string),
  streetB: option(string),
  streetC: option(string),
  streetD: option(string),
  city: string,
  state: string,
  country: string,
  zipcode: string,
  geo: card_address_geo,
};

type card = {
  name: string,
  username: string,
  email: string,
  address: card_address,
  phone: string,
  website: string,
  company: card_company,
  posts: Js.Array.t(card_post),
  accountHistory: Js.Array.t(transaction),
};

type contextual_card = {
  name: string,
  username: string,
  avatar: string,
  email: string,
  dob: Js.Date.t,
  phone: string,
  address: card_address,
  website: string,
  company: card_company,
};

type t = {
  slugify: Js.Nullable.t(string) => string,
  replaceSymbolWithNumber:
    (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  replaceSymbols: Js.Nullable.t(string) => string,
  createCard: unit => card,
  contextualCard: unit => contextual_card,
  userCard: unit => contextual_card,
  createTransaction: unit => transaction,
};

[@bs.module "faker"] external fakers: t = "helpers";

let slugify = (~str=?, ()) => fakers.slugify(nullable(str));
let replaceSymbolWithNumber = (~str=?, ~symbol=?, ()) =>
  fakers.replaceSymbolWithNumber(nullable(str), nullable(symbol));
let replaceSymbols = (~str=?, ()) => fakers.replaceSymbols(nullable(str));
let createCard = () => fakers.createCard();
let contextualCard = () => fakers.contextualCard();

[@bs.module "faker"] [@bs.scope "helpers"]
external randomize: Js.Nullable.t(Js.Array.t('a)) => 'a = "randomize";
let randomize = (~arr=?, ()) => randomize(nullable(arr));

[@bs.module "faker"] [@bs.scope "helpers"]
external shuffle: Js.Nullable.t(Js.Array.t('a)) => Js.Array.t('a) =
  "shuffle";
let shuffle = (~o=?, ()) => shuffle(nullable(o));

[@bs.module "faker"] [@bs.scope "helpers"]
external mustache:
  (Js.Nullable.t(string), Js.Nullable.t(Js.Dict.t('a))) => string =
  "mustache";
let mustache = (~str=?, ~data=?, ()) =>
  mustache(nullable(str), nullable(data));
