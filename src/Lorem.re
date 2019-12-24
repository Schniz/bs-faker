type t = {
  word: unit => string,
  words: option(int) => string,
  sentence: (option(int), unit) => string, /* technically accepts range, but range appears to be unused */
  slug: option(int) => string,
  sentences: (option(int), option(string)) => string,
  paragraph: option(int) => string,
  paragraphs: (option(int), option(string)) => string,
  text: unit => string,
  lines: option(int) => string,
};
[@bs.module "faker"] external fakers: t = "lorem";
let word = () => fakers.word();
let words = (~wordCount=?, ()) => fakers.words(wordCount);
let sentence = (~wordCount=?, ()) => fakers.sentence(wordCount, ());
let slug = (~wordCount=?, ()) => fakers.slug(wordCount);
let sentences = (~sentenceCount=?, ~separator=?, ()) =>
  fakers.sentences(sentenceCount, separator);
let paragraph = (~sentenceCount=?, ()) => fakers.paragraph(sentenceCount);
let paragraphs = (~paragraphCount=?, ~separator=?, ()) =>
  fakers.paragraphs(paragraphCount, separator);
let text = () => fakers.text();
let lines = (~lineCount=?, ()) => fakers.lines(lineCount);
