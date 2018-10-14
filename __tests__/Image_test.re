open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Image", () => {
  test(".avatar", () =>
    expect(Js.typeof(Image.avatar())) === "string"
  );
  test(".abstract", () =>
    expect(Js.typeof(Image.abstract())) === "string"
  );
  test(".animals", () =>
    expect(Js.typeof(Image.animals())) === "string"
  );
  test(".business", () =>
    expect(Js.typeof(Image.business())) === "string"
  );
  test(".cats", () =>
    expect(Js.typeof(Image.cats())) === "string"
  );
  test(".city", () =>
    expect(Js.typeof(Image.city())) === "string"
  );
  test(".dataUri", () =>
    expect(Js.typeof(Image.dataUri())) === "string"
  );
  test(".fashion", () =>
    expect(Js.typeof(Image.fashion())) === "string"
  );
  test(".food", () =>
    expect(Js.typeof(Image.food())) === "string"
  );
  test(".image", () =>
    expect(Js.typeof(Image.image())) === "string"
  );
  test(".imageUrl", () =>
    expect(Js.typeof(Image.imageUrl())) === "string"
  );
  test(".natrue", () =>
    expect(Js.typeof(Image.nature())) === "string"
  );
  test(".nightlife", () =>
    expect(Js.typeof(Image.nightlife())) === "string"
  );
  test(".people", () =>
    expect(Js.typeof(Image.people())) === "string"
  );
  test(".sports", () =>
    expect(Js.typeof(Image.sports())) === "string"
  );
  test(".technics", () =>
    expect(Js.typeof(Image.technics())) === "string"
  );
  test(".transport  ", () =>
    expect(Js.typeof(Image.transport())) === "string"
  );
});
