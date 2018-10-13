let nullable = Js.Nullable.fromOption;
type nullable('a) = Js.Nullable.t('a);

module Image = {
  type fetchImage_js = (nullable(int), nullable(int), nullable(bool)) => string;
  [@bs.deriving abstract]
  type t = {
    avatar: unit => string,
    abstract: fetchImage_js,
    animals: fetchImage_js,
    business: fetchImage_js,
    cats: fetchImage_js,
    city: fetchImage_js,
    dataUri: (nullable(int), nullable(int)) => string,
    fashion: fetchImage_js,
    food: fetchImage_js,
    image: fetchImage_js,
    imageUrl: (nullable(int), nullable(int), nullable(string), nullable(bool), unit) => string,
    nature: fetchImage_js,
    nightlife: fetchImage_js,
    people: fetchImage_js,
    sports: fetchImage_js,
    technics: fetchImage_js,
    transport: fetchImage_js,
  };
  [@bs.module "faker"] external fakers : t = "image";
  let fetchImage = (fn, ~width=?, ~height=?, ~randomize=?, ()) =>
    fn(fakers, nullable(width), nullable(height), nullable(randomize));
  let avatar = () => avatar(fakers, ());
  let dataUri = (~width=?, ~height=?, ()) => dataUri(fakers, nullable(width), nullable(height));
  let imageUrl = (~width=?, ~height=?, ~category=?, ~randomize=?, ()) =>
    imageUrl(fakers, nullable(width), nullable(height), nullable(category), nullable(randomize), ());
  let abstract = fetchImage(abstract);
  let animals = fetchImage(animals);
  let business = fetchImage(business);
  let cats = fetchImage(cats);
  let city = fetchImage(city);
  let fashion = fetchImage(fashion);
  let food = fetchImage(food);
  let image = fetchImage(image);
  let nature = fetchImage(nature);
  let nightlife = fetchImage(nightlife);
  let people = fetchImage(people);
  let sports = fetchImage(sports);
  let technics = fetchImage(technics);
  let transport = fetchImage(transport);
};

module Name = {
  [@bs.deriving abstract]
  type t = {
    findName: (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) => string,
    firstName: Js.Nullable.t(string) => string,
    lastName: Js.Nullable.t(string) => string,
    prefix: Js.Nullable.t(string) => string,
    suffix: unit => string,
    title: unit => string,
    jobArea: unit => string,
    jobType: unit => string,
  };
  [@bs.module "faker"] external fakers : t = "name";
  let findName = (~firstName=?, ~lastName=?, ~gender=?, ()) =>
    findName(fakers, nullable(firstName), nullable(lastName), nullable(gender));
  let firstName = (~gender=?, ()) => firstName(fakers, nullable(gender));
  let lastName = (~gender=?, ()) => lastName(fakers, nullable(gender));
  let prefix = (~gender=?, ()) => prefix(fakers, nullable(gender));
  let suffix = () => suffix(fakers, ());
  let title = () => title(fakers, ());
  let jobArea = () => jobArea(fakers, ());
  let jobType = () => jobType(fakers, ());
};

module Internet = {
  [@bs.deriving abstract]
  type t = {userName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string};
  [@bs.module "faker"] external fakers : t = "internet";
  let userName = (~firstName=?, ~lastName=?, ()) => userName(fakers, nullable(firstName), nullable(lastName));
};

module Lorem = {
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
  let sentences = (~sentenceCount=?, ~separator=?, ()) => sentences(fakers, nullable(sentenceCount), nullable(separator));
  let paragraph = (~sentenceCount=?, ()) => paragraph(fakers, nullable(sentenceCount));
  let paragraphs = (~paragraphCount=?, ~separator=?, ()) => paragraphs(fakers, nullable(paragraphCount), nullable(separator));
  let text = () => text(fakers, ());
  let lines = (~lineCount=?, ()) => lines(fakers, nullable(lineCount));
};

module Date = {
  [@bs.deriving abstract]
  type t = {past: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t};
  [@bs.module "faker"] external fakers : t = "date";
  let past = (~years=?, ~refDate=?, ()) => past(fakers, nullable(years), nullable(refDate));
};

module Company = {
  [@bs.deriving abstract]
  type t = {
    suffixes: unit => Js.Array.t(string),
    companyName: (Js.Nullable.t(int)) => string,
    companySuffix: unit => string,
    catchPhrase: unit => string,
    bs: unit => string,
    catchPhraseAdjective: unit => string,
    catchPhraseDescriptor: unit => string,
    catchPhraseNoun: unit => string,
    bsAdjective: unit => string,
    bsBuzz: unit => string,
    bsNoun: unit => string
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
}

module Phone = {
  [@bs.deriving abstract]
  type t = {
    phoneNumber: Js.Nullable.t(string) => string,
    phoneNumberFormat: int => string,
    phoneFormats: unit => string,
  };
  [@bs.module "faker"] external fakers : t = "phone";
  let phoneNumber = (~format=?, ()) =>
    phoneNumber(fakers, nullable(format));
  let phoneNumberFormat = (~phoneFormatsIndex) =>
    phoneNumberFormat(fakers, phoneFormatsIndex);
  let phoneFormats = () => phoneFormats(fakers, ());
};

module Random = {
  [@bs.deriving abstract]
  type t = {
    alphaNumeric: Js.Nullable.t(int) => string,
    boolean: unit => bool,
    image: unit => string,
    locale: unit => string,
  };
  [@bs.module "faker"] external fakers : t = "random";
  let alphaNumeric = (~count=?, ()) =>
    alphaNumeric(fakers, nullable(count));
  let boolean = () => boolean(fakers, ());
  let image = () => image(fakers, ());
  let locale = () => locale(fakers, ());
}

module Fake = {
  [@bs.module "faker"] external _fake : string => string = "fake";
  let fake = input => {
    switch (_fake(input)) {
    | value => Belt.Result.Ok(value)
    | exception Js.Exn.Error(x) => Belt.Result.Error(x)
    };
  };
};

let fake = Fake.fake;
