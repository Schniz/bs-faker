let nullable = Faker.nullable;

type fetchImage_js =
  (Js.Nullable.t(int), Js.Nullable.t(int), Js.Nullable.t(bool)) => string;


type t = {
  avatar: unit => string,
  abstract: fetchImage_js,
  animals: fetchImage_js,
  business: fetchImage_js,
  cats: fetchImage_js,
  city: fetchImage_js,
  dataUri: (Js.Nullable.t(int), Js.Nullable.t(int)) => string,
  fashion: fetchImage_js,
  food: fetchImage_js,
  image: fetchImage_js,
  imageUrl:
    (
      Js.Nullable.t(int),
      Js.Nullable.t(int),
      Js.Nullable.t(string),
      Js.Nullable.t(bool),
      unit
    ) =>
    string,
  nature: fetchImage_js,
  nightlife: fetchImage_js,
  people: fetchImage_js,
  sports: fetchImage_js,
  technics: fetchImage_js,
  transport: fetchImage_js,
};

[@bs.module "faker"] external fakers : t = "image";

let fetchImage = (fn, ~width=?, ~height=?, ~randomize=?, ()) =>
  fn( nullable(width), nullable(height), nullable(randomize));
let avatar = () => fakers.avatar( ());
let dataUri = (~width=?, ~height=?, ()) =>
  fakers.dataUri( nullable(width), nullable(height));
let imageUrl = (~width=?, ~height=?, ~category=?, ~randomize=?, ()) =>
  fakers.imageUrl(
    nullable(width),
    nullable(height),
    nullable(category),
    nullable(randomize),
    (),
  );
let abstract = fetchImage(fakers.abstract);
let animals = fetchImage(fakers.animals);
let business = fetchImage(fakers.business);
let cats = fetchImage(fakers.cats);
let city = fetchImage(fakers.city);
let fashion = fetchImage(fakers.fashion);
let food = fetchImage(fakers.food);
let image = fetchImage(fakers.image);
let nature = fetchImage(fakers.nature);
let nightlife = fetchImage(fakers.nightlife);
let people = fetchImage(fakers.people);
let sports = fetchImage(fakers.sports);
let technics = fetchImage(fakers.technics);
let transport = fetchImage(fakers.transport);
