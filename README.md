# bs-faker [![Build Status](https://travis-ci.org/Schniz/bs-faker.svg?branch=master)](https://travis-ci.org/Schniz/bs-faker) ![BuckleScript binding coverage](https://img.shields.io/badge/binding%20coverage-135%2F148-yellowgreen.svg)

> [Faker.js](https://github.com/marak/Faker.js/) bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason)

# Install

```
npm install --save bs-faker
```

Then add `bs-faker` as a dependency to `bsconfig.json`:

```diff
  ...
  "bs-dependencies": [
    // add your dependencies here. You'd usually install them normally through `npm install my-dependency`. If my-dependency has a bsconfig.json too, then everything will work seamlessly.
+   "bs-faker"
  ]
  ...
```

## API

When using optional params (`~param=?`), don't forget to add a unit `()` parameter in the end to invoke the function
like so:

```reason
let narrowFood = BsFaker.Image.food(~width=200, ()); /* => "https://someimage/with/width/of/200" */

/* Without the optional parameters, you don't have to add the unit */
let defaultFood = BsFaker.Image.food(); /* => "https://someimage/with/default/width" */
```

### `BsFaker.fake`
Creates a string with fake data using mustache style templates.
Returns a safe, `result` type instead of throwing an error on runtime.

```reason
let message = BsFaker.Faker.fake("Welcome aboard, {{name.firstName}}");
switch (message) {
| Ok(msg) => print_endline(msg)
| Error(_) => print_endline("Parsing error")
};
```

### `BsFaker.Image`

```reason
let avatar = BsFaker.Image.avatar(); /* => string; "https://" */
let abstract = BsFaker.Image.abstract(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let animals = BsFaker.Image.animals(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let business = BsFaker.Image.business(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let cats = BsFaker.Image.cats(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let city = BsFaker.Image.city(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let dataUri = BsFaker.Image.dataUri(~width: int=?, ~height: int=?, ()); /* => string; "data:inage/svg+xml;..." */
let fashion = BsFaker.Image.fashion(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let food = BsFaker.Image.food(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let image = BsFaker.Image.image(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let imageUrl = BsFaker.Image.imageUrl(~width: int=?, ~height: int=?, ~category: string=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/640/480" */
let nature = BsFaker.Image.nature(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let nightlife = BsFaker.Image.nightlife(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let people = BsFaker.Image.people(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let sports = BsFaker.Image.sports(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let technics = BsFaker.Image.technics(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let transport = BsFaker.Image.transport(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
```

### `BsFaker.Name`

```reason
let findName = BsFaker.Name.findName(~firstName: string=?, ~lastName: string=?, ~gender: string=?, ()); /* => string; "Mollie Hills" */
let firstName = BsFaker.Name.firstName(~gender: string=?, ()); /* => string; "Max" */
let lastName = BsFaker.Name.lastName(~gender: string=?, ()); /* => string; "Bartoletti" */
let prefix = BsFaker.Name.prefix(~gender: string=?, ()); /* => string; "Dr." */
let suffix = BsFaker.Name.suffix(); /* => string; "MD" */
let title = BsFaker.Name.title(); /* => string; "Senior Creative Specialist" */
let jobArea = BsFaker.Name.jobArea(); /* => string; "Tactics" */
let jobType = BsFaker.Name.jobType(); /* => string; "Assistant" */
```

### `BsFaker.Lorem`
```reason
let word = BsFaker.Lorem.word(); /* => string; "Lorem" */
let words = BsFaker.Lorem.words(~wordCount=3, ()); /* => string; "Lorem ipsum dolor" */
let sentence = BsFaker.Lorem.sentence(~wordCount=5, ()); /* => string; "Lorem ipsum dolor est totam" */
let slug = BsFaker.Lorem.slug(~wordCount=3, ()); /* => string; "lorem-ratione-est" */
let sentences = BsFaker.Lorem.sentences(~sentenceCount=3, ~separator=";;;", ()); /* => string; "Lorem ipsum....;;;Et ratione est..." */
let paragraph = BsFaker.Lorem.paragraph(~sentenceCount=2, ()); /* => string; "Et ratione est totam assumenda ..." */
let paragraphs = BsFaker.Lorem.paragraphs(~paragraphCount=3, ~separator="\n----\n", ()); /* => string */
let text = BsFaker.Lorem.text(); /* => string; "Et lorem est dolor totam... */
let lines = BsFaker.Lorem.lines(~lineCount=3, ()); /* => string; */
```

### `BsFaker.Date`
```reason
let past = BsFaker.Date.past(~years: int=?, ~refDate: Js.Date.t=?, ()); /* => Js.Date.t; */
let future = BsFaker.Date.future(~years: int=?, ~refDate: Js.Date.t=?, ()); /* => Js.Date.t; */
let between = BsFaker.Date.between(Js.Date.t, Js.Date.t); /* => Js.Date.t; */
let recent = BsFaker.Date.recent(~days: int=?, ()); /* => Js.Date.t; */
let month: (~abbr: bool=?, ~context: bool=?, ()); /* => string; */
let weekday: (~abbr: bool=?, ~context: bool=?, ()); /* => string; */
```

### `BsFaker.Company`
```reason
let suffixes = BsFaker.Company.suffixes(); /* => ["and Sons", "Co.", "Inc."] */
let companyName = BsFaker.Company.companyName(~format=2, ()); /* => "Dewey, Cheatem and Howe" */
let companySuffix = BsFaker.Company.companySuffix(); /* => "Co." */
let catchPhrase = BsFaker.Company.catchPhrase(); /* => string */
let bs = BsFaker.Company.bs(); /* => string */
let catchPhraseAdjective = BsFaker.Company.catchPhraseAdjective(); /* => string */
let catchPhraseDescriptor = BsFaker.Company.catchPhraseDescriptor(); /* => string */
let catchPhraseNoun = BsFaker.Company.catchPhraseNoun(); /* => string */
let bsAdjective = BsFaker.Company.bsAdjective(); /* => string */
let bsBuzz = BsFaker.Company.bsBuzz(); /* => string */
let bsNoun = BsFaker.Company.bsNoun(); /* => string */
```

### `BsFaker.Phone`
```reason
let phoneNumber = BsFaker.Phone.phoneNumber(~format="###.###.####", ()); /* => string; "621.876.3963" */
let phoneNumberFormat = BsFaker.Phone.phoneNumberFormat(~phoneFormatsIndex=0); /* => string; "107-646-3702" */
let phoneFormats = BsFaker.Phone.phoneFormats(); /* => string; "###-###-#### x###" */
```

### `BsFaker.Internet`
```reason
let userName = BsFaker.Internet.userName(~firstName: string=?, ~lastName: string=?, ()); /* => string; "Rage.Max123" */
let avatar = BsFaker.Internet.avatar(); /* => string; "https://s3.amazonaws.com/uifaces/faces/twitter/igorgarybaldi/128.jpg" */
let email = BsFaker.Internet.email(); /* => string; ": "foo.bar@gmail.com" */
let exampleEmail = BsFaker.Internet.exampleEmail(); /* => string; "foo.bar@example.org" */
let protocol = BsFaker.Internet.protocol(); /* => string; "https" */
let url = BsFaker.Internet.url(); /* => string; "https://rashawn.name" */
let domainName = BsFaker.Internet.domainName(); /* => string; "marvin.org" */
let domainSuffix = BsFaker.Internet.domainSuffix(); /* => string; "net" */
let domainWord = BsFaker.Internet.domainWord(); /* => string; "alyce" */
let ip = BsFaker.Internet.ip(); /* => string; "97.238.241.11" */
let ipv6 = BsFaker.Internet.ipv6(); /* => string; "2001:0db8:6276:b1a7:5213:22f1:25df:c8a0" */
let userAgent = BsFaker.Internet.userAgent(); /* => string; "Mozilla/5.0 (Macintosh; U; PPC Mac OS X 10_7_5 rv:6.0; SL) AppleWebKit/532.0.1 (KHTML, like Gecko)" */
let color = BsFaker.Internet.color(); /* => string; "#06267f" */
let mac = BsFaker.Internet.mac(); /* => string; "78:06:cc:ae:b3:81" */
let password = BsFaker.Internet.password(); /* => string; "AM7zl6Mg" */
```

### `BsFaker.Random`
```reason
let alphaNumeric = BsFaker.Random.alphaNumeric(~count=5, ()); /* => string; "9fedl" */
let arrayElement = BsFaker.Random.arrayElement(~array=[| 126, -3, 58, 31 |], ()); /* => int; 58 */
let boolean = BsFaker.Random.boolean(); /* => boolean; true */
let image = BsFaker.Random.image(); /* => string; "http://lorempixel.com/640/480/city" */
let locale = BsFaker.Random.locale(); /* => string; "sk" */
let number = BsFaker.Random.number(~min=0, ~max=150, ~precision=5, ()); /* => int; 65 */
let uuid = BsFaker.Random.uuid(); /* => string; "053cf30a-e38a-4327-936a-e5e2991f6b7f" */
let word = BsFaker.Random.word(); /* => string; "Gibraltar" */
let words = BsFaker.Random.words(~count=3, ()); /* => string; "Savings Account function Executive" */
```

### `BsFaker.Database`
```reason
let column = BsFaker.Database.column(); /* => string; "id" */
let type_ = BsFaker.Database.type_(); /* => string; "byte" */
let collation = BsFaker.Database.collation(); /* => string; "utf8_unicode_ci" */
let engine = BsFaker.Database.engine(); /* => string; "MyISAM" */
```

### `BsFaker.Hacker`
```reason
let abbreviation = BsFaker.Hacker.abbreviation(); /* => string; "XSS" */
let adjective = BsFaker.Hacker.adjective(); /* => string; "primary" */
let noun = BsFaker.Hacker.noun(); /* => string; "capacitor" */
let verb = BsFaker.Hacker.verb(); /* => string; "synthesize" */
let ingverb = BsFaker.Hacker.ingverb(); /* => string; "hacking" */
let phrase = BsFaker.Hacker.phrase(); /* => string; "You can't transmit the program without overriding the bluetooth RSS port!" */
```

### `BsFaker.System`
```reason
let fileName = BsFaker.System.fileName(); /* => string; "optical.xsm" */
let commonFileName = BsFaker.System.commonFileName(~ext="txt", ()); /* => string; "redundant.txt" */
let mimeType = BsFaker.System.mimeType(); /* => string; "audio/webm" */
let commonFileType = BsFaker.System.commonFileType(); /* => string; "text" */
let commonFileExt = BsFaker.System.commonFileExt(); /* => string; "png" */
let fileType = BsFaker.System.fileType(); /* => string; "audio" */
let fileExt = BsFaker.System.fileExt(~mimeType="audio/webm", ()); /* => string; "model" */
let semver = BsFaker.System.semver(); /* => string; "0.8.1" */
```

### `BsFaker.Commerce`

```reason
let color = BsFaker.Commerce.color(); /* => string; "maroon" */
let department = BsFaker.Commerce.department(); /* => string; "Music" */
let productName = BsFaker.Commerce.productName(); /* => string; "Licensed Steel Keyboard" */
let price = BsFaker.Commerce.price(~min=0, ~max=1000, ~decimal=2, ~symbol="$", ()); /* => string; "$580.00" */
let productAdjective = BsFaker.Commerce.productAdjective(); /* => string; "Handcrafted" */
let productMaterial = BsFaker.Commerce.productMaterial(); /* => string; "Granite" */
let product = BsFaker.Commerce.product(); /* => string; "Salad" */
```

### `BsFaker.Locale`
`setLocale` function accepts parameter in form of variant.
The variant's constructors are capitalized locale ids of available locales, i.e. `Az` | `Cz` | `De` | `En_GB` etc.

```reason
let () = BsFaker.Locale.setLocale(Sk); /* => unit */
let locale = BsFaker.Locale.getLocale(); /* => string; "sk" */
```

### `BsFaker.Finance`

```reason
let account = BsFaker.Finance.account(~length=4, ()); /* => string; "6738" */
let accountName = BsFaker.Finance.accountName(); /* => string; "Personal Loan Account" */
let amount = BsFaker.Finance.amount(~min=50, ~max=100, ~dec=2, ~symbol="$", ()); /* => string; "$53.54" */
let bic = BsFaker.Finance.bic(); /* => string; "DYTOFXJ1362" */
let bitcoinAddress = BsFaker.Finance.bitcoinAddress(); /* => string; "17C4J6I0UE9O4Y5UCOFCWLG2RYPA5HMP" */
let currencyCode = BsFaker.Finance.currencyCode(); /* => string; "KMF" */
let currencyName = BsFaker.Finance.currencyName(); /* => string; "Zloty" */
let currencySymbol = BsFaker.Finance.currencySymbol(); /* => string; "CHF" */
let iban = BsFaker.Finance.iban(); /* => string; "SE1400277200550070250082" */
let mask = BsFaker.Finance.mask(~length=4, ~parens=true, ~ellipsis=true, ()); /* => string; "(...8899)" */
let transactionType = BsFaker.Finance.transactionType(); /* => string; "invoice" */
```

### `BsFaker.Address`

```reason
let city = (~format: string=?, ()); /* => string; */
let cityPrefix = (); /* => string; */
let citySuffix = (); /* => string; */
let country = (); /* => string; */
let countryCode = (); /* => string; */
let county = (); /* => string; */
let latitude = (); /* => string; */
let longitude = (); /* => string; */
let secondaryAddress = (); /* => string; */
let state = (~useAbbr: bool=?, ()); /* => string; */
let stateAbbr = (); /* => string; */
let streetAddress = (~useFullAddress: bool=?, ()); /* => string; */
let streetName = (); /* => string; */
let streetPrefix = (); /* => string; */
let streetSuffix = (); /* => string; */
let zipCode = (~format: string=?, ()); /* => string; */
```

# Testing the library

```
npm test
```

this will compile and execute tests with `bs-jest`

# Contributions

Don't hesitate to open a PR with a new binding - while bumping up the amount of covered bindings in the README.
There are tests, use them and write the most simple test you can think of to make sure that the bindings work correctly.
[You can read more about contributing here](CONTRIBUTING.md)
