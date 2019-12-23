type t = {
  suffixes: unit => Js.Array.t(string),
  companyName: option(int) => string,
  companySuffix: unit => string,
  catchPhrase: unit => string,
  bs: unit => string,
  catchPhraseAdjective: unit => string,
  catchPhraseDescriptor: unit => string,
  catchPhraseNoun: unit => string,
  bsAdjective: unit => string,
  bsBuzz: unit => string,
  bsNoun: unit => string,
};
[@bs.module "faker"] external fakers: t = "company";
let suffixes = () => fakers.suffixes();
let companyName = (~format=?, ()) => fakers.companyName(format);
let companySuffix = () => fakers.companySuffix();
let catchPhrase = () => fakers.catchPhrase();
let bs = () => fakers.bs();
let catchPhraseAdjective = () => fakers.catchPhraseAdjective();
let catchPhraseDescriptor = () => fakers.catchPhraseDescriptor();
let catchPhraseNoun = () => fakers.catchPhraseNoun();
let bsAdjective = () => fakers.bsAdjective();
let bsBuzz = () => fakers.bsBuzz();
let bsNoun = () => fakers.bsNoun();
