open Webapi.Dom;

type action =
  | UpdateRoute(ReasonReact.Router.url);

type state = ReasonReact.Router.url;

let component = ReasonReact.reducerComponent("Router");

let make: 'a => ReasonReact.component(state, _, action) =
  children => {
    ...component,
    initialState: () => {path: [], hash: "", search: ""},
    didMount: (_) =>
      switch [%external window] {
      | None => ReasonReact.NoUpdate
      | Some(window) =>
        let appLoad = Event.make("popstate");
        let _ = Window.dispatchEvent(appLoad, window);
        ReasonReact.NoUpdate;
      },
    reducer: (action, _state) =>
      switch action {
      | UpdateRoute(url) => ReasonReact.Update(url)
      },
    subscriptions: ({send}) => [
      Sub(
        () => ReasonReact.Router.watchUrl(url => send(UpdateRoute(url))),
        ReasonReact.Router.unwatchUrl
      )
    ],
    render: ({state}) => children(state)
  };