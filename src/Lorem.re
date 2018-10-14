let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  word: unit => string,
  words: Js.Nullable.t(int) => string,
  sentence: (Js.Nullable.t(int), unit) => string, /* technically accepts range, but range appears to be unused */
  slug: Js.Nullable.t(int) => string,
  sentences: (Js.Nullable.t(int), Js.Nullable.t(string)) => string,
  paragraph: Js.Nullable.t(int) => string,
  paragraphs: (Js.Nullable.t(int), Js.Nullable.t(string)) => string,
  text: unit => string,
  lines: Js.Nullable.t(int) => string,
};
[@bs.module "faker"] external fakers : t = "lorem";
let word = () => word(fakers, ());
let words = (~wordCount=?, ()) => words(fakers, nullable(wordCount));
let sentence = (~wordCount=?, ()) => sentence(fakers, nullable(wordCount), ());
let slug = (~wordCount=?, ()) => slug(fakers, nullable(wordCount));
let sentences = (~sentenceCount=?, ~separator=?, ()) =>
  sentences(fakers, nullable(sentenceCount), nullable(separator));
let paragraph = (~sentenceCount=?, ()) => paragraph(fakers, nullable(sentenceCount));
let paragraphs = (~paragraphCount=?, ~separator=?, ()) =>
  paragraphs(fakers, nullable(paragraphCount), nullable(separator));
let text = () => text(fakers, ());
let lines = (~lineCount=?, ()) => lines(fakers, nullable(lineCount));
