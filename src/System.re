let nullable = Faker.nullable;

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
let commonFileExt = (~type_=?, ()) => commonFileExt(fakers, nullable(type_));
let fileType = () => fileType(fakers, ());
let fileExt = (~mimeType=?, ()) => fileExt(fakers, nullable(mimeType));
let semver = () => semver(fakers, ());
