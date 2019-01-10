open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Date", () => {
  describe(".past", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Date.past())) === "object"
    );

    test("accepts years", () =>
      expect(Date.past(~years=1, ()) |> Js.Date.valueOf)
      |> toBeLessThanOrEqual(Js.Date.now())
    );

    test("accepts refDate", () => {
      let refDate =
        Js.Date.utcWithYM(~year=2000., ~month=0., ()) |> Js.Date.fromFloat;
      expect(Date.past(~refDate, ()) |> Js.Date.valueOf)
      |> toBeLessThanOrEqual(refDate |> Js.Date.valueOf);
    });
  });

  describe(".future", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Date.future())) === "object"
    );

    test("accepts years", () =>
      expect(Date.future(~years=1, ()) |> Js.Date.valueOf)
      |> toBeGreaterThanOrEqual(Js.Date.now())
    );

    test("accepts refDate", () => {
      let refDate =
        Js.Date.utcWithYM(~year=2000., ~month=0., ()) |> Js.Date.fromFloat;
      expect(Date.future(~refDate, ()) |> Js.Date.valueOf)
      |> toBeGreaterThanOrEqual(refDate |> Js.Date.valueOf);
    });
  });

  describe(".between", () => {
    test("returns date greater than or equal to `from` date", () => {
      let from =
        Js.Date.utcWithYM(~year=2000., ~month=0., ()) |> Js.Date.fromFloat;
      let to_ =
        Js.Date.utcWithYM(~year=2000., ~month=1., ()) |> Js.Date.fromFloat;
      expect(Date.between(from, to_) |> Js.Date.valueOf)
      |> toBeGreaterThanOrEqual(from |> Js.Date.valueOf);
    });

    test("returns date less than or equal to `to_` date", () => {
      let from =
        Js.Date.utcWithYM(~year=2000., ~month=0., ()) |> Js.Date.fromFloat;
      let to_ =
        Js.Date.utcWithYM(~year=2000., ~month=1., ()) |> Js.Date.fromFloat;
      expect(Date.between(from, to_) |> Js.Date.valueOf)
      |> toBeLessThanOrEqual(to_ |> Js.Date.valueOf);
    });
  });

  describe(".recent", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Date.recent())) === "object"
    );

    test("accepts days", () =>
      expect(Date.recent(~days=1, ()) |> Js.Date.valueOf)
      |> toBeLessThanOrEqual(Js.Date.now())
    );
  });

  describe(".month", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Date.month())) === "string"
    );

    test("accepts abbr", () =>
      expect(Js.typeof(Date.month(~abbr=true, ()))) === "string"
    );

    test("accepts context", () =>
      expect(Js.typeof(Date.month(~context=true, ()))) === "string"
    );
  });

  describe(".weekday", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Date.weekday())) === "string"
    );

    test("accepts abbr", () =>
      expect(Js.typeof(Date.weekday(~abbr=true, ()))) === "string"
    );

    test("accepts context", () =>
      expect(Js.typeof(Date.weekday(~context=true, ()))) === "string"
    );
  });
});
