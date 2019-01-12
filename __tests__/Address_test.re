open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Address", () => {
  describe(".city", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Address.city())) === "string"
    );

    test("accepts format", () =>
      expect(Js.typeof(Address.city(~format="{{address.cityPrefix}}", ())))
      === "string"
    );
  });

  test(".cityPrefix", () =>
    expect(Js.typeof(Address.cityPrefix())) === "string"
  );

  test(".citySuffix", () =>
    expect(Js.typeof(Address.citySuffix())) === "string"
  );

  test(".country", () =>
    expect(Js.typeof(Address.country())) === "string"
  );

  test(".countryCode", () =>
    expect(Js.typeof(Address.countryCode())) === "string"
  );

  test(".county", () =>
    expect(Js.typeof(Address.county())) === "string"
  );

  test(".latitude", () =>
    expect(Js.typeof(Address.latitude())) === "string"
  );

  test(".longitude", () =>
    expect(Js.typeof(Address.longitude())) === "string"
  );

  test(".secondaryAddress", () =>
    expect(Js.typeof(Address.secondaryAddress())) === "string"
  );

  describe(".state", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Address.state())) === "string"
    );

    test("accepts useAbbr", () =>
      expect(Js.typeof(Address.state(~useAbbr=true, ()))) === "string"
    );
  });

  test(".stateAbbr", () =>
    expect(Js.typeof(Address.stateAbbr())) === "string"
  );

  describe(".streetAddress", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Address.streetAddress())) === "string"
    );

    test("accepts useFullAddress", () =>
      expect(Js.typeof(Address.streetAddress(~useFullAddress=true, ())))
      === "string"
    );
  });

  test(".streetName", () =>
    expect(Js.typeof(Address.streetName())) === "string"
  );

  test(".streetSuffix", () =>
    expect(Js.typeof(Address.streetSuffix())) === "string"
  );

  test(".streetPrefix", () =>
    expect(Js.typeof(Address.streetPrefix())) === "string"
  );

  describe(".zipCode", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Address.zipCode())) === "string"
    );

    test("accepts format", () =>
      expect(
        Js.typeof(Address.zipCode(~format="{{address.cityPrefix}}", ())),
      )
      === "string"
    );
  });
});
