let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  suffixes: unit => Js.Array.t(string),
  companyName: Js.Nullable.t(int) => string,
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
[@bs.module "faker"] external fakers : t = "company";
let suffixes = () => suffixes(fakers, ());
let companyName = (~format=?, ()) => companyName(fakers, nullable(format));
let companySuffix = () => companySuffix(fakers, ());
let catchPhrase = () => catchPhrase(fakers, ());
let bs = () => bs(fakers, ());
let catchPhraseAdjective = () => catchPhraseAdjective(fakers, ());
let catchPhraseDescriptor = () => catchPhraseDescriptor(fakers, ());
let catchPhraseNoun = () => catchPhraseNoun(fakers, ());
let bsAdjective = () => bsAdjective(fakers, ());
let bsBuzz = () => bsBuzz(fakers, ());
let bsNoun = () => bsNoun(fakers, ());
