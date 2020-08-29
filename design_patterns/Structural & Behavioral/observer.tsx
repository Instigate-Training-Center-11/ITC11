class User {
  name: string;
  status: string;
  constructor(name: string, status: string) {
    this.name = name;
    this.status = status;
  }
}

class EventManager {
  followers: Array<EventListener> = [];

  subscribe(listener: EventListener) {
    this.followers.push(listener);
  }

  unsubscribe(listener: string) {
    this.followers = this.followers.filter((el) => el.name !== listener);
  }

  notify(username: string) {
    this.followers.forEach((element) => {
      element.update(username);
    });
  }
}

class Editor {
  events: EventManager;
  user: User = { name: "Ben", status: "status" };
  constructor() {
    this.events = new EventManager();
  }

  updateStatus() {
    this.user.status = "new status";
    this.events.notify(this.user.name);
  }
}

abstract class EventListener {
  abstract update(username: string): void;
}

class LoggingListener extends EventListener {
  message: string;
  constructor(message: string) {
    super();
    this.message = message;
  }

  update(username: string): void {
    console.log(this.message.replace("%u", username));
  }
}

const editor = new Editor();
const logger = new LoggingListener("%u changed status");

editor.events.subscribe(logger);
editor.updateStatus();
