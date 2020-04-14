import React, { Fragment } from 'react';
import {
  Text, Button
} from 'react-native';

class MyFirstClassComponent extends React.Component {

    constructor(props) {
      super(props);
      this.state = {
        name: '',
        surname: ''
      }
    }

    componentDidMount = () => {
        this.setState({ name: "John", surname: "Doe"});
    }

    updateUser = () => {
      this.setState({ name: "Satya", surname: "Nadella"});
    }

    render() {
      return (
        <Fragment>
          <Text>This is my first class component</Text>

          <Button title="Update name" onPress={this.updateUser} />

          <Text>Hello {this.state.name} {this.state.surname}</Text>
        </Fragment>
      )
    }
}

export default MyFirstClassComponent;