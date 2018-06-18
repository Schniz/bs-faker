# bs-faker ![BuckleScript binding coverage](https://img.shields.io/badge/binding%20coverage-12%2F148-red.svg)

[Faker.js](https://github.com/marak/Faker.js/) bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason)

# Install

```
npm install --save bs-faker
```

Then add `bs-faker` as a dependency to `bsconfig.json`

# Usage

Right now the library is somewhat underdocumented, so please view the interface file `Faker.rei` to see library usage.

# Testing the library

```
npm test
```

this will compile and execute tests with `bs-jest`

# Contributions

Don't hesitate to open a PR with a new binding - while bumping up the amount of covered bindings in the README.
There are tests, use them and write the most simple test you can think of to make sure that the bindings work correctly.
