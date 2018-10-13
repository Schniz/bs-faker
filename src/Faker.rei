module Image: {
  let avatar: unit => string;
  let abstract: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let animals: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let business: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let cats: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let city: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let dataUri: (~width: int=?, ~height: int=?, unit) => string;
  let fashion: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let food: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let image: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let imageUrl: (~width: int=?, ~height: int=?, ~category: string=?, ~randomize: bool=?, unit) => string;
  let nature: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let nightlife: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let people: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let sports: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let technics: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
  let transport: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
};

module Name: {
  let findName: (~firstName: string=?, ~lastName: string=?, ~gender: string=?, unit) => string;
  let firstName: (~gender: string=?, unit) => string;
  let lastName: (~gender: string=?, unit) => string;
  let prefix: (~gender: string=?, unit) => string;
  let suffix: unit => string;
  let title: unit => string;
  let jobArea: unit => string;
  let jobType: unit => string;
};

module Internet: {let userName: (~firstName: string=?, ~lastName: string=?, unit) => string;};

module Lorem: {
  let word: unit => string;
  let words: (~wordCount: int=?, unit) => string;
  let sentence: (~wordCount: int=?, unit) => string;
  let slug: (~wordCount: int=?, unit) => string;
  let sentences: (~sentenceCount: int=?, ~separator: string=?, unit) => string;
  let paragraph: (~sentenceCount: int=?, unit) => string;
  let paragraphs: (~paragraphCount: int=?, ~separator: string=?, unit) => string;
  let text: unit => string;
  let lines: (~lineCount: int=?, unit) => string;
};

module Date: {let past: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;};

module Company: {
  let suffixes: unit => Js.Array.t(string);
  let companyName: (~format: int=?, unit) => string
  let companySuffix: unit => string;
  let catchPhrase: unit => string;
  let bs: unit => string;
  let catchPhraseAdjective: unit => string;
  let catchPhraseDescriptor: unit => string;
  let catchPhraseNoun: unit => string;
  let bsAdjective: unit => string;
  let bsBuzz: unit => string;
  let bsNoun: unit => string;
};

module Phone: {
  let phoneNumber: (~format: string=?, unit) => string;
  let phoneNumberFormat: (~phoneFormatsIndex: int) => string;
  let phoneFormats: unit => string;
};

module Random: {
  let alphaNumeric: (~count: int=?, unit) => string;
  let arrayElement: (~array: Js.Array.t('a)) => option('a);
  let boolean: unit => bool;
  let image: unit => string;
  let locale: unit => string;
}

let fake: string => Belt.Result.t(string, Js.Exn.t);
