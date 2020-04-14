import React, { Fragment } from 'react';
import {
  Text,
  Button
} from 'react-native';

interface Props {

}

interface State {
    name: string,
    surname: string
}

class MyFirstClassComponent extends React.Component<Props, State> {

    constructor(props: Props) {
      super(props);
      this.state = {
        name: '',
        surname: ''
      }
    }

    updateUser = () => {
        this.setState({ name: "Satya", surname: "Nadella"});
      }

    componentDidMount = () => {
        this.setState({ name: "John", surname: "Doe"});
    }

    render() {
      return (
        <Fragment>
          <Text>This is my first class component</Text>
          <Button title="Update name" onPress={this.updateUser} />
          <Text>Hello {this.state.name} {this.state.surname} with TypeScript!</Text>
        </Fragment>
      )
    }
}

export default MyFirstClassComponent;