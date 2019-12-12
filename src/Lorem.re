let nullable = Faker.nullable;


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
let word = () => fakers.word( ());
let words = (~wordCount=?, ()) => fakers.words( nullable(wordCount));
let sentence = (~wordCount=?, ()) => fakers.sentence( nullable(wordCount), ());
let slug = (~wordCount=?, ()) => fakers.slug( nullable(wordCount));
let sentences = (~sentenceCount=?, ~separator=?, ()) =>
  fakers.sentences( nullable(sentenceCount), nullable(separator));
let paragraph = (~sentenceCount=?, ()) => fakers.paragraph( nullable(sentenceCount));
let paragraphs = (~paragraphCount=?, ~separator=?, ()) =>
  fakers.paragraphs( nullable(paragraphCount), nullable(separator));
let text = () => fakers.text( ());
let lines = (~lineCount=?, ()) => fakers.lines( nullable(lineCount));
