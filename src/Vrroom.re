type nothing;

module Helpers = {
  type childless = array(nothing);

  module Text = {
    let string  = ReasonReact.stringToElement;
    let int     = n => n |> string_of_int   |> string;
    let float   = f => f |> string_of_float |> string;
    let any     = v => v |> Js.String.make  |> string;
  };

  let text = Text.string;
  let nothing = ReasonReact.nullElement;
  let nbsp = [%raw {|'\u00a0'|}];

  [@deprecated "deprecated in favor of [nothing]"]
  let null = ReasonReact.nullElement;

  module ClassName = {
    let join = items =>
      items |> List.filter((!==)(""))
            |> String.concat(" ");
    
    let if_   = (cond, cls) =>
      cond ? cls : "";

    let fromOption =
      fun | Some(cls) => cls
          | None      => ""
  };
};

include Helpers;

let pure = make => {
  let instance = ReasonReact.statelessComponent("Pure");
  make((element, _:childless) => {
    ...instance,
    render: _self => element
  });
};

module Fragment = {
  [@bs.module "react"] external reactClass : ReasonReact.reactClass = "Fragment";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Control = {
  module Map = {
    let component = ReasonReact.statelessComponent("Control.Map");
    let make = (~items: array('a),
                ~empty: ReasonReact.reactElement=nothing,
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        <Fragment>
          {
            switch items {
            | [||] => empty
            | _    => items |> Array.map(render)
                            |> ReasonReact.arrayToElement
            }
          }
        </Fragment>
    };
  };

  module MapList = {
    let component = ReasonReact.statelessComponent("Control.MapList");
    let make = (~items: list('a),
                ~empty: ReasonReact.reactElement=nothing,
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
      <Map items=(items |> Array.of_list) empty>
        ...render
      </Map>
    };
  };

  module If = {
    let component = ReasonReact.statelessComponent("Control.If");
    let make = (~cond: bool,
                render: unit => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        cond ? render() : nothing
    };
  };

  module IfSome = {
    let component = ReasonReact.statelessComponent("Control.IfSome");
    let make = (~option: option('a),
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        switch option {
        | Some(value) => render(value)
        | None        => nothing
        }
    };
  };
};