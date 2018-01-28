let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Router>
      ...(
           (url: ReasonReact.Router.url) =>
             <div>
               (
                 switch url.path {
                 | [] => "Home page" |> text
                 | ["about"] => "ReasonReact Router - about page" |> text
                 | ["posts", id] => "Posts id #" ++ id |> text
                 | _ => "404 not found" |> text
                 }
               )
             </div>
         )
    </Router>
};