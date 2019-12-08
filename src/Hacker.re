type t = {
  abbreviation: unit => string,
  adjective: unit => string,
  noun: unit => string,
  verb: unit => string,
  ingverb: unit => string,
  phrase: unit => string,
};

[@bs.module "faker"] external fakers: t = "hacker";

let abbreviation = () => fakers.abbreviation();
let adjective = () => fakers.adjective();
let noun = () => fakers.noun();
let verb = () => fakers.verb();
let ingverb = () => fakers.ingverb();
let phrase = () => fakers.phrase();