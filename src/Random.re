type number_options_t = {
  min: option(int),
  max: option(int),
  precision: option(int),
};

type t = {
  alphaNumeric: option(int) => string,
  boolean: unit => bool,
  image: unit => string,
  locale: unit => string,
  number: number_options_t => int,
  uuid: unit => string,
  word: unit => string,
  words: option(int) => string,
};
[@bs.module "faker"] external fakers: t = "random";

let alphaNumeric = (~count=?, ()) => fakers.alphaNumeric(count);
let boolean = () => fakers.boolean();
let image = () => fakers.image();
let locale = () => fakers.locale();
let number = (~min=0, ~max=99999, ~precision=1, ()) => {
  let options: number_options_t = {
    min: Some(min),
    max: Some(max),
    precision: Some(precision),
  };
  fakers.number(options);
};
let uuid = () => fakers.uuid();
let word = () => fakers.word();
let words = (~count=?, ()) => fakers.words(count);

[@bs.module "faker"] [@bs.scope "random"]
external arrayElement: Js.Array.t('a) => Js.Nullable.t('a) = "arrayElement";
let arrayElement = (~array) => Js.Nullable.toOption(arrayElement(array));
