module Arrow = {
  external arrow : ReactRe.reactClass = "Arrow" [@@bs.module "rebass"];
  let createElement = ReactRe.wrapPropsShamelessly arrow (Js.Obj.empty ());
};

module Button = {
  external button : ReactRe.reactClass = "Button" [@@bs.module "rebass"];
  let createElement ::onClick=? style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly
      button
      {"onClick": Js.Null_undefined.from_opt onClick, "style": Js.Null_undefined.from_opt style};
};

module Dropdown = {
  external dropdown : ReactRe.reactClass = "Dropdown" [@@bs.module];
  let createElement ::style=? =>
    ReactRe.wrapPropsShamelessly
      dropdown {"style": Js.Null_undefined.from_opt (style: option ReactDOMRe.style)};
};

module DropdownMenu = {
  external dropdownMenu : ReactRe.reactClass = "DropdownMenu" [@@bs.module];
  let createElement
      open_::(open_: option bool)=?
      onDismiss::(onDismiss: option (ReactEventRe.Form.t => unit))=?
      right::(right: option bool)=? =>
    ReactRe.wrapPropsShamelessly
      dropdownMenu
      {
        "open":
          switch open_ {
          | Some value => Js.Boolean.to_js_boolean value
          | None => Js.false_
          },
        "onDismiss": Js.Null_undefined.from_opt onDismiss,
        "right":
          switch right {
          | Some value => Js.Boolean.to_js_boolean value
          | None => Js.false_
          }
      };
};

module Heading = {
  external heading : ReactRe.reactClass = "Heading" [@@bs.module];
  let createElement style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly heading {"style": Js.Null_undefined.from_opt style};
};

module NavItem = {
  external navItem : ReactRe.reactClass = "NavItem" [@@bs.module];
  let createElement style::(style: option ReactDOMRe.style)=? =>
    ReactRe.wrapPropsShamelessly navItem {"style": Js.Null_undefined.from_opt style};
};
