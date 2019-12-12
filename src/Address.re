let nullable = Faker.nullable;

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
[@bs.module "faker"] external fakers: t = "address";
let city = (~format=?, ()) => fakers.city(nullable(format));
let cityPrefix = () => fakers.cityPrefix();
let citySuffix = () => fakers.citySuffix();
let country = () => fakers.country();
let countryCode = () => fakers.countryCode();
let county = () => fakers.county();
let latitude = () => fakers.latitude();
let longitude = () => fakers.longitude();
let secondaryAddress = () => fakers.secondaryAddress();
let state = (~useAbbr=?, ()) => fakers.state(nullable(useAbbr));
let stateAbbr = () => fakers.stateAbbr();
let streetAddress = (~useFullAddress=?, ()) =>
  fakers.streetAddress(nullable(useFullAddress));
let streetName = () => fakers.streetName();
let streetPrefix = () => fakers.streetPrefix();
let streetSuffix = () => fakers.streetSuffix();
let zipCode = (~format=?, ()) => fakers.zipCode(nullable(format));
