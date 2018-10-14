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
  type number_options_t = {
    [@bs.optional] min: int,
    [@bs.optional] max: int,
    [@bs.optional] precision: int,
  };
  [@bs.deriving abstract]
  type t = {
    alphaNumeric: Js.Nullable.t(int) => string,
    boolean: unit => bool,
    image: unit => string,
    locale: unit => string,
    number: number_options_t => int,
    uuid: unit => string,
    word: unit => string,
    words: Js.Nullable.t(int) => string
  };
  [@bs.module "faker"] external fakers : t = "random";
  let alphaNumeric = (~count=?, ()) =>
    alphaNumeric(fakers, nullable(count));
  let boolean = () => boolean(fakers, ());
  let image = () => image(fakers, ());
  let locale = () => locale(fakers, ());
  let number = (~min=0, ~max=99999, ~precision=1, ()) => {
    let options = number_options_t(~min, ~max, ~precision, ());
    number(fakers, options);
  };
  let uuid = () => uuid(fakers, ());
  let word = () => word(fakers, ());
  let words = (~count=?, ()) => words(fakers, nullable(count));

  [@bs.module "faker"] [@bs.scope "random"]
  external arrayElement : Js.Array.t('a) => nullable('a) = "";
  let arrayElement = (~array) => Js.Nullable.toOption(arrayElement(array));
};

module Database = {
  [@bs.deriving abstract]
  type t = {
    column: unit => string,
    type_: unit => string,
    collation: unit => string,
    engine: unit => string,
  };
  [@bs.module "faker"] external fakers : t = "database";
  let column = () => column(fakers, ());
  [@bs.module "faker"] [@bs.scope "database"] [@bs.val] external type_ : unit => string = "type";
  let type_ = () => type_();
  let collation = () => collation(fakers, ());
  let engine = () => engine(fakers, ());
};

module System = {
  [@bs.deriving abstract]
  type t = {
    fileName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
    commonFileName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
    mimeType: unit => string,
    commonFileType: unit => string,
    commonFileExt: Js.Nullable.t(string) => string,
    fileType: unit => string,
    fileExt: Js.Nullable.t(string) => string,
    semver: unit => string,
  };

  [@bs.module "faker"] external fakers : t = "system";

  /*
     Optional ext and type arguments are ignored by faker.js.
     See https://github.com/Marak/faker.js/issues/687
     Therefore they are not tested.
   */
  let fileName = (~ext=?, ~type_=?, ()) =>
    fileName(fakers, nullable(ext), nullable(type_));

  /*
     Optional type argument is ignored by faker.js.
     See https://github.com/Marak/faker.js/issues/687
     Therefore it is not tested.
   */
  let commonFileName = (~ext=?, ~type_=?, ()) =>
    commonFileName(fakers, nullable(ext), nullable(type_));
  let mimeType = () => mimeType(fakers, ());
  let commonFileType = () => commonFileType(fakers, ());

  /*
     Optional type argument is ignored by faker.js.
     Therefore it is not tested.
   */
  let commonFileExt = (~type_=?, ()) =>
    commonFileExt(fakers, nullable(type_));
  let fileType = () => fileType(fakers, ());
  let fileExt = (~mimeType=?, ()) => fileExt(fakers, nullable(mimeType));
  let semver = () => semver(fakers, ());
};

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

module Locale = {
  type locale = Az | Cz | De | De_AT | De_CH | En | En_AU | En_BORK | En_CA
    | En_GB | En_IE | En_IND | En_US | En_au_ocker | Es | Es_MX | Fa | Fr | Fr_CA
    | Ge | Id_ID | It | Ja | Ko | Nb_NO | Nep | Nl | Pl | Pt_BR | Ru | Sk | Sv
    | Tr | Uk | Vi | Zh_CN | Zh_TW;

  [@bs.deriving abstract]
  type t = {mutable locale: string};
  
  [@bs.module] external faker : t = "faker";

  let getLocale = () => locale(faker);

  let string_from_locale = fun
    | Az => "az" | Cz => "cz" | De => "de" | De_AT => "de_AT" | De_CH => "de_CH"
    | En => "en" | En_AU => "en_AU" | En_BORK => "en_BORK" | En_CA => "en_CA"
    | En_GB => "en_GB" | En_IE => "en_IE" | En_IND => "en_IND" | En_US => "en_US"
    | En_au_ocker => "en_au_ocker" | Es => "es" | Es_MX => "es_MX" | Fa => "fa"
    | Fr => "fr" | Fr_CA => "fr_CA" | Ge => "ge" | Id_ID => "id_ID" | It => "it"
    | Ja => "ja" | Ko => "ko" | Nb_NO => "nb_NO" | Nep => "nep" | Nl => "nl"
    | Pl => "pl" | Pt_BR => "pt_BR" | Ru => "ru" | Sk => "sk" | Sv => "sv"
    | Tr => "tr" | Uk => "uk" | Vi => "vi" | Zh_CN => "zh_CN" | Zh_TW => "zh_TW"
  ;

  let setLocale = (locale) => {
    let locale_string = string_from_locale(locale);
    localeSet(faker, locale_string);
  };
};

module Commerce = {
  [@bs.deriving abstract]
  type t = {
    color: unit => string,
    department: unit => string,
    productName: unit => string,
    price: (int, int, int, string) => string,
    productAdjective: unit => string,
    productMaterial: unit => string,
    product: unit => string,
  };

  [@bs.module "faker"] external fakers : t = "commerce";

  let color = () => color(fakers, ());
  let department = () => department(fakers, ());
  let productName = () => productName(fakers, ());
  let price = (~min=0, ~max=1000, ~decimal=2, ~symbol="", ()) =>
    price(fakers, min, max, decimal, symbol);
  let productAdjective = () => productAdjective(fakers, ());
  let productMaterial = () => productMaterial(fakers, ());
  let product = () => product(fakers, ());
};
