let word: unit => string;
let words: (~wordCount: int=?, unit) => string;
let sentence: (~wordCount: int=?, unit) => string;
let slug: (~wordCount: int=?, unit) => string;
let sentences: (~sentenceCount: int=?, ~separator: string=?, unit) => string;
let paragraph: (~sentenceCount: int=?, unit) => string;
let paragraphs: (~paragraphCount: int=?, ~separator: string=?, unit) => string;
let text: unit => string;
let lines: (~lineCount: int=?, unit) => string;
