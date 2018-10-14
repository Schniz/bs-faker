let avatar: unit => string;
let abstract: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let animals: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let business: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let cats: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let city: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let dataUri: (~width: int=?, ~height: int=?, unit) => string;
let fashion: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let food: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let image: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let imageUrl:
  (~width: int=?, ~height: int=?, ~category: string=?, ~randomize: bool=?, unit) =>
  string;
let nature: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let nightlife: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let people: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let sports: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let technics: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
let transport: (~width: int=?, ~height: int=?, ~randomize: bool=?, unit) => string;
