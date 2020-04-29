import React, { Fragment, useState } from 'react';
import {
  Text, Button
} from 'react-native';


const MyFirstFunctionalComponentWithState = (props) => {
    const [fcName, setFCName] = useState(props.name);

    return(
        <Fragment>
            <Text>This is my first functional component</Text>
            <Text>Hello from {fcName}</Text>
            <Button title="Click" onPress={() => setFCName("Mike")}/>
        </Fragment>
    )
}

export default MyFirstFunctionalComponentWithState;