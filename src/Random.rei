let alphaNumeric: (~count: int=?, unit) => option(string);
let arrayElement: (~array: Js.Array.t('a)) => option('a);
let boolean: unit => bool;
let image: unit => string;
let locale: unit => string;
let number: (~min: int=?, ~max: int=?, ~precision: int=?, unit) => int;
let uuid: unit => string;
let word: unit => string;
let words: (~count: int=?, unit) => option(string);
