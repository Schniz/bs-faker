type t = {
  city: option(string) => string,
  cityPrefix: unit => string,
  citySuffix: unit => string,
  country: unit => string,
  countryCode: unit => string,
  county: unit => string,
  latitude: unit => string,
  longitude: unit => string,
  secondaryAddress: unit => string,
  state: option(bool) => string,
  stateAbbr: unit => string,
  streetAddress: option(bool) => string,
  streetName: unit => string,
  streetPrefix: unit => string,
  streetSuffix: unit => string,
  zipCode: option(string) => string,
};
[@bs.module "faker"] external fakers: t = "address";
let city = (~format=?, ()) => fakers.city(format);
let cityPrefix = () => fakers.cityPrefix();
let citySuffix = () => fakers.citySuffix();
let country = () => fakers.country();
let countryCode = () => fakers.countryCode();
let county = () => fakers.county();
let latitude = () => fakers.latitude();
let longitude = () => fakers.longitude();
let secondaryAddress = () => fakers.secondaryAddress();
let state = (~useAbbr=?, ()) => fakers.state(useAbbr);
let stateAbbr = () => fakers.stateAbbr();
let streetAddress = (~useFullAddress=?, ()) =>
  fakers.streetAddress(useFullAddress);
let streetName = () => fakers.streetName();
let streetPrefix = () => fakers.streetPrefix();
let streetSuffix = () => fakers.streetSuffix();
let zipCode = (~format=?, ()) => fakers.zipCode(format);