# bs-faker [![Build Status](https://travis-ci.org/Schniz/bs-faker.svg?branch=master)](https://travis-ci.org/Schniz/bs-faker) ![BuckleScript binding coverage](https://img.shields.io/badge/binding%20coverage-51%2F148-red.svg)
> [Faker.js](https://github.com/marak/Faker.js/) bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason)

# Install

```
npm install --save bs-faker
```

Then add `bs-faker` as a dependency to `bsconfig.json`

# Usage

Don't hesitate to view the interface file `Faker.rei` to see library usage.

## API

When using optional params (`~param=?`), don't forget to add a unit `()` parameter in the end to invoke the function
like so:

```reason
let narrowFood = Faker.Image.food(~width=200, ()); /* => "https://someimage/with/width/of/200" */

/* Without the optional parameters, you don't have to add the unit */
let defaultFood = Faker.Image.food(); /* => "https://someimage/with/default/width" */
```

### `Faker.fake`
Creates a string with fake data using mustache style templates.
Returns a safe, `result` type instead of throwing an error on runtime.

```reason
let message = Faker.fake("Welcome aboard, {{name.firstName}}");
switch (message) {
| Ok(msg) => print_endline(msg)
| Error(_) => print_endline("Parsing error")
};
```

### `Faker.Image`

```reason
let avatar = Faker.Image.avatar(); /* => string; "https://" */
let abstract = Faker.Image.abstract(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let animals = Faker.Image.animals(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let business = Faker.Image.business(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let cats = Faker.Image.cats(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let city = Faker.Image.city(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let dataUri = Faker.Image.dataUri(~width: int=?, ~height: int=?, ()); /* => string; "data:inage/svg+xml;..." */
let fashion = Faker.Image.fashion(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let food = Faker.Image.food(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let image = Faker.Image.image(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let imageUrl = Faker.Image.imageUrl(~width: int=?, ~height: int=?, ~category: string=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/640/480" */
let nature = Faker.Image.nature(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let nightlife = Faker.Image.nightlife(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let people = Faker.Image.people(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let sports = Faker.Image.sports(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let technics = Faker.Image.technics(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
let transport = Faker.Image.transport(~width: int=?, ~height: int=?, ~randomize: bool=?, ()); /* => string; "http://lorempixel.com/..." */
```

### `Faker.Name`

```reason
let findName = Faker.Name.findName(~firstName: string=?, ~lastName: string=?, ~gender: string=?, ()); /* => string; "Mollie Hills" */
let firstName = Faker.Name.firstName(~gender: string=?, ()); /* => string; "Max" */
let lastName = Faker.Name.lastName(~gender: string=?, ()); /* => string; "Bartoletti" */
let prefix = Faker.Name.prefix(~gender: string=?, ()); /* => string; "Dr." */
let suffix = Faker.Name.suffix(); /* => string; "MD" */
let title = Faker.Name.title(); /* => string; "Senior Creative Specialist" */
let jobArea = Faker.Name.jobArea(); /* => string; "Tactics" */
let jobType = Faker.Name.jobType(); /* => string; "Assistant" */
```

### `Faker.Internet`

```reason
let userName = Faker.Internet.userName(~firstName: string=?, ~lastName: string=?, ()); /* => string; "Rage.Max123" */
```

### `Faker.Lorem`
```reason
let word = Faker.Lorem.word(); /* => string; "Lorem" */
let words = Faker.Lorem.words(~wordCount=3, ()); /* => string; "Lorem ipsum dolor" */
let sentence = Faker.Lorem.sentence(~wordCount=5, ()); /* => string; "Lorem ipsum dolor est totam" */
let slug = Faker.Lorem.slug(~wordCount=3, ()); /* => string; "lorem-ratione-est" */
let sentences = Faker.Lorem.sentences(~sentenceCount=3, ~separator=";;;", ()); /* => string; "Lorem ipsum....;;;Et ratione est..." */
let paragraph = Faker.Lorem.paragraph(~sentenceCount=2, ()); /* => string; "Et ratione est totam assumenda ..." */
let paragraphs = Faker.Lorem.paragraphs(~paragraphCount=3, ~separator="\n----\n", ()); /* => string */
let text = Faker.Lorem.text(); /* => string; "Et lorem est dolor totam... */
let lines = Faker.Lorem.lines(~lineCount=3, ()); /* => string; */
```

### `Faker.Date`
```reason
let past = Faker.Date.past(~years: int=?, ~refDate: Js.Date.t=?, ()); /* => Js.Date.t; */
```

### `Faker.Company`
```reason
let suffixes = Faker.Company.suffixes(); /* => ["and Sons", "Co.", "Inc."] */
let companyName = Faker.Company.companyName(~format=2, ()); /* => "Dewey, Cheatem and Howe" */
let companySuffix = Faker.Company.companySuffix(); /* => "Co." */
let catchPhrase = Faker.Company.catchPhrase(); /* => string */
let bs = Faker.Company.bs(); /* => string */
let catchPhraseAdjective = Faker.Company.catchPhraseAdjective(); /* => string */
let catchPhraseDescriptor = Faker.Company.catchPhraseDescriptor(); /* => string */
let catchPhraseNoun = Faker.Company.catchPhraseNoun(); /* => string */
let bsAdjective = Faker.Company.bsAdjective(); /* => string */
let bsBuzz = Faker.Company.bsBuzz(); /* => string */
let bsNoun = Faker.Company.bsNoun(); /* => string */
```

### `Faker.Phone`
```reason
let phoneNumber = Faker.Phone.phoneNumber(~format="###.###.####", ()); /* => string; "621.876.3963" */
let phoneNumberFormat = Faker.Phone.phoneNumberFormat(~phoneFormatsIndex=0); /* => string; "107-646-3702" */
let phoneFormats = Faker.Phone.phoneFormats(); /* => string; "###-###-#### x###" */
```

### `Faker.Random`
```reason
let alphaNumeric = Faker.Random.alphaNumeric(~count=5, ()); /* => string; "9fedl" */
let arrayElement = Faker.Random.arrayElement(~array=[| 126, -3, 58, 31 |], ()); /* => int; 58 */
let boolean = Faker.Random.boolean(); /* => boolean; true */
let image = Faker.Random.image(); /* => string; "http://lorempixel.com/640/480/city" */
let locale = Faker.Random.locale(); /* => string; "sk" */
let number = Faker.Random.number(~min=0, ~max=150, ~precision=5, ()); /* => int; 65 */
let uuid = Faker.Random.uuid(); /* => string; "053cf30a-e38a-4327-936a-e5e2991f6b7f" */
let word = Faker.Random.word(); /* => string; "Gibraltar" */
let words = Faker.Random.words(~count=3, ()); /* => string; "Savings Account function Executive" */
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
