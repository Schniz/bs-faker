type t = {
  phoneNumber: option(string) => string,
  phoneNumberFormat: int => string,
  phoneFormats: unit => string,
};
[@bs.module "faker"] external fakers: t = "phone";
let phoneNumber = (~format=?, ()) => Some(fakers.phoneNumber(format));
let phoneNumberFormat = (~phoneFormatsIndex) =>
  fakers.phoneNumberFormat(phoneFormatsIndex);
let phoneFormats = () => fakers.phoneFormats();
