[@bs.deriving abstract]
type t = {
  abbreviation: unit => string,
  adjective: unit => string,
  noun: unit => string,
  verb: unit => string,
  ingverb: unit => string,
  phrase: unit => string,
};

[@bs.module "faker"] external fakers : t = "hacker";

let abbreviation = () => abbreviation(fakers, ());
let adjective = () => adjective(fakers, ());
let noun = () => noun(fakers, ());
let verb = () => verb(fakers, ());
let ingverb = () => ingverb(fakers, ());
let phrase = () => phrase(fakers, ());
