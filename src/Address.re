let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  city: Js.Nullable.t(string) => string,
  cityPrefix: unit => string,
  citySuffix: unit => string,
  country: unit => string,
  countryCode: unit => string,
  county: unit => string,
  latitude: unit => string,
  longitude: unit => string,
  secondaryAddress: unit => string,
  state: Js.Nullable.t(bool) => string,
  stateAbbr: unit => string,
  streetAddress: Js.Nullable.t(bool) => string,
  streetName: unit => string,
  streetPrefix: unit => string,
  streetSuffix: unit => string,
  zipCode: Js.Nullable.t(string) => string,
};
[@bs.module "faker"] external fakers : t = "address";
let city = (~format=?, ()) => city(fakers, nullable(format));
let cityPrefix = () => cityPrefix(fakers, ());
let citySuffix = () => citySuffix(fakers, ());
let country = () => country(fakers, ());
let countryCode = () => countryCode(fakers, ());
let county = () => county(fakers, ());
let latitude = () => latitude(fakers, ());
let longitude = () => longitude(fakers, ());
let secondaryAddress = () => secondaryAddress(fakers, ());
let state = (~useAbbr=?, ()) => state(fakers, nullable(useAbbr));
let stateAbbr = () => stateAbbr(fakers, ());
let streetAddress = (~useFullAddress=?, ()) =>
  streetAddress(fakers, nullable(useFullAddress));
let streetName = () => streetName(fakers, ());
let streetPrefix = () => streetPrefix(fakers, ());
let streetSuffix = () => streetSuffix(fakers, ());
let zipCode = (~format=?, ()) => zipCode(fakers, nullable(format));
