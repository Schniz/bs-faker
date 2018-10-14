let fileName: (~ext: string=?, ~type_: string=?, unit) => string;
let commonFileName: (~ext: string=?, ~type_: string=?, unit) => string;
let mimeType: unit => string;
let commonFileType: unit => string;
let commonFileExt: (~type_: string=?, unit) => string;
let fileType: unit => string;
let fileExt: (~mimeType: string=?, unit) => string;
let semver: unit => string;
