let nullable = Faker.nullable;

[@bs.deriving abstract]
type number_options_t = {
  [@bs.optional] min: int,
  [@bs.optional] max: int,
  [@bs.optional] precision: int,
};

[@bs.deriving abstract]
type t = {
  alphaNumeric: Js.Nullable.t(int) => string,
  boolean: unit => bool,
  image: unit => string,
  locale: unit => string,
  number: number_options_t => int,
  uuid: unit => string,
  word: unit => string,
  words: Js.Nullable.t(int) => string,
};
[@bs.module "faker"] external fakers : t = "random";

let alphaNumeric = (~count=?, ()) => alphaNumeric(fakers, nullable(count));
let boolean = () => boolean(fakers, ());
let image = () => image(fakers, ());
let locale = () => locale(fakers, ());
let number = (~min=0, ~max=99999, ~precision=1, ()) => {
  let options = number_options_t(~min, ~max, ~precision, ());
  number(fakers, options);
};
let uuid = () => uuid(fakers, ());
let word = () => word(fakers, ());
let words = (~count=?, ()) => words(fakers, nullable(count));

[@bs.module "faker"] [@bs.scope "random"]
external arrayElement : Js.Array.t('a) => Js.Nullable.t('a) = "";
let arrayElement = (~array) => Js.Nullable.toOption(arrayElement(array));
